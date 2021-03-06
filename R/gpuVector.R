#' @title Construct a gpuVector
#' @description Construct a gpuVector of a class that inherits
#' from \code{gpuVector}
#' @param data An object that is or can be converted to a 
#' \code{vector}
#' @param length A non-negative integer specifying the desired length.
#' @param type A character string specifying the type of gpuVector.  Default
#' is NULL where type is inherited from the source data type.
#' @param ctx_id An integer specifying the object's context
#' @param ... Additional method to pass to gpuVector methods
#' @return A gpuVector object
#' @docType methods
#' @rdname gpuVector-methods
#' @author Charles Determan Jr.
#' @export
setGeneric("gpuVector", function(data, length, type=NULL, ...){
    standardGeneric("gpuVector")
})

#' @rdname gpuVector-methods
#' @aliases gpuVector,vector
setMethod('gpuVector', 
          signature(data = 'vector', length = 'missing'),
          function(data, type=NULL, ctx_id = NULL){
              
              if (is.null(type)){
                  if(typeof(data) == "integer") {
                      type <- "integer"
                  }else{
                      type <- getOption("gpuR.default.type")    
                  }
              }
              
              device <- if(is.null(ctx_id)) currentDevice() else listContexts()[ctx_id,]
              
              context_index <- ifelse(is.null(ctx_id), currentContext(), as.integer(ctx_id))
              device_index <- if(is.null(ctx_id)) as.integer(device$device_index) else device$device_index + 1L
              
              platform_index <- if(is.null(ctx_id)) currentPlatform()$platform_index else device$platform_index + 1L
              platform_name <- platformInfo(platform_index)$platformName
              
              device_type <- device$device_type
              device_name <- switch(device_type,
                                    "gpu" = gpuInfo(
                                        device_idx = as.integer(device_index),
                                        context_idx = context_index)$deviceName,
                                    "cpu" = cpuInfo(
                                        device_idx = as.integer(device_index),
                                        context_idx = context_index)$deviceName,
                                    stop("Unrecognized device type")
              )
              
              out = switch(type,
                            integer = {
                                new("igpuVector", 
                                    address=sexpVecToEigenVecXptr(data, 
                                                                  length(data),
                                                                  4L),
                                    .context_index = context_index,
                                    .platform_index = platform_index,
                                    .platform = platform_name,
                                    .device_index = device_index,
                                    .device = device_name)
                            },
                            float = {
                                new("fgpuVector", 
                                    address=sexpVecToEigenVecXptr(data, 
                                                                  length(data),
                                                                  6L),
                                    .context_index = context_index,
                                    .platform_index = platform_index,
                                    .platform = platform_name,
                                    .device_index = device_index,
                                    .device = device_name)
                            },
                            double = {
                                assert_has_double(device_index, context_index)
                                new("dgpuVector",
                                    address = sexpVecToEigenVecXptr(data,
                                                                    length(data),
                                                                    8L),
                                    .context_index = context_index,
                                    .platform_index = platform_index,
                                    .platform = platform_name,
                                    .device_index = device_index,
                                    .device = device_name)
                            },
                            stop("this is an unrecognized 
                                 or unimplemented data type")
              )
              
              return(out)
          },
          valueClass = "gpuVector"
)


#' @rdname gpuVector-methods
#' @aliases gpuVector,missingOrNULL
setMethod('gpuVector', 
          signature(data = 'missingOrNULL'),
          function(data, length, type=NULL, ctx_id = NULL){
              
              if (is.null(type)) type <- getOption("gpuR.default.type")
              if (length <= 0) stop("length must be a positive integer")
              if (!is.integer(length)) stop("length must be a positive integer")
              
              device <- if(is.null(ctx_id)) currentDevice() else listContexts()[ctx_id,]
              
              context_index <- ifelse(is.null(ctx_id), currentContext(), as.integer(ctx_id))
              device_index <- if(is.null(ctx_id)) as.integer(device$device_index) else device$device_index + 1L
              
              platform_index <- if(is.null(ctx_id)) currentPlatform()$platform_index else device$platform_index + 1L
              platform_name <- platformInfo(platform_index)$platformName
              
              device_type <- device$device_type
              device_name <- switch(device_type,
                                    "gpu" = gpuInfo(
                                        device_idx = as.integer(device_index),
                                        context_idx = context_index)$deviceName,
                                    "cpu" = cpuInfo(
                                        device_idx = as.integer(device_index),
                                        context_idx = context_index)$deviceName,
                                    stop("Unrecognized device type")
              )
              
              out = switch(type,
                            integer = {
                                new("igpuVector", 
                                    address=emptyEigenVecXptr(length, 4L),
                                    .context_index = context_index,
                                    .platform_index = platform_index,
                                    .platform = platform_name,
                                    .device_index = device_index,
                                    .device = device_name)
                            },
                            float = {
                                new("fgpuVector", 
                                    address=emptyEigenVecXptr(length, 6L),
                                    .context_index = context_index,
                                    .platform_index = platform_index,
                                    .platform = platform_name,
                                    .device_index = device_index,
                                    .device = device_name)
                            },
                            double = {
                                assert_has_double(device_index, context_index)
                                new("dgpuVector",
                                    address = emptyEigenVecXptr(length, 8L),
                                    .context_index = context_index,
                                    .platform_index = platform_index,
                                    .platform = platform_name,
                                    .device_index = device_index,
                                    .device = device_name)
                            },
                            stop("this is an unrecognized 
                                 or unimplemented data type")
              )
              
              return(out)
          },
          valueClass = "gpuVector"
)


#' @rdname gpuVector-methods
#' @aliases gpuVector,vector
setMethod('gpuVector', 
          signature(data = 'numeric', length = 'numericOrInt'),
          function(data, length, type=NULL, ctx_id = NULL){
              
              if (is.null(type)) type <- getOption("gpuR.default.type")
              
              device <- if(is.null(ctx_id)) currentDevice() else listContexts()[ctx_id,]
              
              context_index <- ifelse(is.null(ctx_id), currentContext(), ctx_id)
              device_index <- if(is.null(ctx_id)) as.integer(device$device_index) else device$device_index + 1L
              
              platform_index <- if(is.null(ctx_id)) currentPlatform()$platform_index else device$platform_index + 1L
              platform_name <- platformInfo(platform_index)$platformName
              
              device_type <- device$device_type
              device_name <- switch(device_type,
                                    "gpu" = gpuInfo(
                                        device_idx = as.integer(device_index),
                                        context_idx = context_index)$deviceName,
                                    "cpu" = cpuInfo(
                                        device_idx = as.integer(device_index),
                                        context_idx = context_index)$deviceName,
                                    stop("Unrecognized device type")
              )
              
              data = switch(type,
                            integer = {
                                new("igpuVector", 
                                    address=cpp_scalar_gpuVector(data, length, 4L),
                                    .context_index = context_index,
                                    .platform_index = platform_index,
                                    .platform = platform_name,
                                    .device_index = device_index,
                                    .device = device_name)
                            },
                            float = {
                                new("fgpuVector", 
                                    address=cpp_scalar_gpuVector(data, length, 6L),
                                    .context_index = context_index,
                                    .platform_index = platform_index,
                                    .platform = platform_name,
                                    .device_index = device_index,
                                    .device = device_name)
                            },
                            double = {
                                assert_has_double(device_index, context_index)
                                new("dgpuVector",
                                    address = cpp_scalar_gpuVector(data, length, 8L),
                                    .context_index = context_index,
                                    .platform_index = platform_index,
                                    .platform = platform_name,
                                    .device_index = device_index,
                                    .device = device_name)
                            },
                            stop("this is an unrecognized 
                                 or unimplemented data type")
                            )
              
              return(data)
          },
          valueClass = "gpuVector")

