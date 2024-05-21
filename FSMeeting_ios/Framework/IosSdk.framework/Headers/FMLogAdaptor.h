//
//  FMLogAdaptor.h
//  FastMeeting
//
//  Created by Loki-mac on 15/6/18.
//  Copyright (c) 2015年 Loki-mac. All rights reserved.
//

#import <Foundation/Foundation.h>

#define FMLOG(logString) [FMLogAdaptor Log:logString];
#define FMLOG2(logString) [FMLogAdaptor Log2:logString];
#define FMLOGFormat(formatString,arg...) [FMLogAdaptor Log:[NSString stringWithFormat:formatString,##arg]];

@interface FMLogAdaptor : NSObject

+(void)Log:(NSString*)logString;

+(void)Log2:(NSString*)logString;

+(void)LogWithFormat:(NSString*)formatString,...;

@end
