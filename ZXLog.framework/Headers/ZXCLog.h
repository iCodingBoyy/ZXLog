//
//  ZXCLog.h
//  ZXLog
//
//  Created by 远征 马 on 2018/10/17.
//  Copyright © 2018 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum {
    ZXLevelAll = 0,
    ZXLevelVerbose = 0,
    ZXLevelDebug,    // Detailed information on the flow through the system.
    ZXLevelInfo,     // Interesting runtime events (startup/shutdown), should be conservative and keep to a minimum.
    ZXLevelWarn,     // Other runtime situations that are undesirable or unexpected, but not necessarily "wrong".
    ZXLevelError,    // Other runtime errors or unexpected conditions.
    ZXLevelFatal,    // Severe errors that cause premature termination.
    ZXLevelNone,     // Special level used to disable all log messages.
} ZXLogLevel;




@interface ZXCLog : NSObject
+ (instancetype)sharedLog;
/**
 log初始化
 */

/**
 xlog初始化

 @param logPath 设置log的路径，如果为nil，则使用 Document/ZXLog 路径
 @param logFileName log文件名，如果不设置，则使用iOS_ZXLog_日期
 */
- (void)xlogInitWithPath:(NSString*)logPath logFileName:(NSString*)logFileName;

/**
 关闭log服务
 */
- (void)xlogClose;

+ (void)logWithLevel:(ZXLogLevel)logLevel moduleName:(const char*)moduleName fileName:(const char*)fileName lineNumber:(int)lineNumber funcName:(const char*)funcName message:(NSString *)message;
+ (void)logWithLevel:(ZXLogLevel)logLevel moduleName:(const char*)moduleName fileName:(const char*)fileName lineNumber:(int)lineNumber funcName:(const char*)funcName format:(NSString *)format, ...;

+ (BOOL)shouldLog:(ZXLogLevel)level;
@end


