//
//  LayoutEvent.h
//  IosSdk
//
//  Created by yanhd on 2021/8/24.
//
#import <IosSdk/IosSdk.h>
#import "SDKDataType.h"

NS_ASSUME_NONNULL_BEGIN

@interface LayoutEvent : NSObject
//布局样式
@property (nonatomic,assign)_LayoutMode layoutMode;
//全屏的显示样式 
@property (nonatomic,strong) FullAreaObj* fullArea;
//单个全屏数据
@property (nonatomic,strong) DataBlockObj* fullDataBlock;
//共享类数据 如白板
@property (nonatomic, strong) AreaDataObj *tabArea;
//视频类数据 单个视频小窗
@property (nonatomic, strong) AreaDataObj *splitArea;

//新老协议
@property (nonatomic, assign) BOOL isNewProtocol;
@end

NS_ASSUME_NONNULL_END
