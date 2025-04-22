//
//  BaseManager.h
//  IosSdk
//
//  Created by Tiger on 2021/7/24.
//

#import <Foundation/Foundation.h>
#import "ManagerDelegate.h"
#import "SDKDataType.h"
NS_ASSUME_NONNULL_BEGIN
@interface BaseManager : NSObject
-(void)initManager;
-(void)releaseManager;
-(void)removeEventListener;
-(void)meetingWillStart;
-(void)meetingDidStart;
-(void)meetingWillFinish;
@end

NS_ASSUME_NONNULL_END
