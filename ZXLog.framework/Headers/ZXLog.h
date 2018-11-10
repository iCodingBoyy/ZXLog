//
//  ZXLog.h
//  ZXLog
//
//  Created by 远征 马 on 2018/10/17.
//  Copyright © 2018 马远征. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for ZXLog.
FOUNDATION_EXPORT double ZXLogVersionNumber;

//! Project version string for ZXLog.
FOUNDATION_EXPORT const unsigned char ZXLogVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ZXLog/PublicHeader.h>
#if __has_include(<ZXLog/ZXLog.h>)
    #import <ZXLog/ZXCLog.h>
#else
    #import "ZXLog/ZXCLog.h"
#endif


#define ZLogInternal(level, module, file, line, func, prefix, format, ...) \
do { \
if ([ZXCLog shouldLog:level]) { \
NSString *aMessage = [NSString stringWithFormat:@"%@%@", prefix, [NSString stringWithFormat:format, ##__VA_ARGS__, nil]]; \
[ZXCLog logWithLevel:level moduleName:module fileName:file lineNumber:line funcName:func message:aMessage]; \
} \
} while(0)

#define __FILENAME__ (strrchr(__FILE__,'/')+1)

/**
 *  Module Logging
 */
#define ZLOG_ERROR(module, format, ...) ZLogInternal(ZXLevelError, module, __FILENAME__, __LINE__, __FUNCTION__, @"Error:", format, ##__VA_ARGS__)
#define ZLOG_WARNING(module, format, ...) ZLogInternal(ZXLevelWarn, module, __FILENAME__, __LINE__, __FUNCTION__, @"Warning:", format, ##__VA_ARGS__)
#define ZLOG_INFO(module, format, ...) ZLogInternal(ZXLevelInfo, module, __FILENAME__, __LINE__, __FUNCTION__, @"Info:", format, ##__VA_ARGS__)
#define ZLOG_DEBUG(module, format, ...) ZLogInternal(ZXLevelDebug, module, __FILENAME__, __LINE__, __FUNCTION__, @"Debug:", format, ##__VA_ARGS__)


#if DEBUG
#define ZLog(format, ...) ZLOG_DEBUG(NULL,format, ...)
#else
#define ZLog(format, ...) ZLOG_INFO(NULL, format, ...)
#endif
