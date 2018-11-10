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


#define LogInternal(level, module, file, line, func, prefix, format, ...) \
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
#define LOG_ERROR(module, format, ...) LogInternal(ZXLevelError, module, __FILENAME__, __LINE__, __FUNCTION__, @"Error:", format, ##__VA_ARGS__)
#define LOG_WARNING(module, format, ...) LogInternal(ZXLevelWarn, module, __FILENAME__, __LINE__, __FUNCTION__, @"Warning:", format, ##__VA_ARGS__)
#define LOG_INFO(module, format, ...) LogInternal(ZXLevelInfo, module, __FILENAME__, __LINE__, __FUNCTION__, @"Info:", format, ##__VA_ARGS__)
#define LOG_DEBUG(module, format, ...) LogInternal(ZXLevelDebug, module, __FILENAME__, __LINE__, __FUNCTION__, @"Debug:", format, ##__VA_ARGS__)


#if DEBUG
#define ZLog(format, ...) LogInternal(ZXLevelDebug, NULL, __FILENAME__, __LINE__, __FUNCTION__, @"Debug:", format, ##__VA_ARGS__);
#else
#define ZLog(format, ...) LogInternal(ZXLevelInfo, NULL, __FILENAME__, __LINE__, __FUNCTION__, @"Info:", format, ##__VA_ARGS__);
#endif
