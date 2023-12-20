//
//  WhiteBoardManager.h
//  IosSdk
//
//  Created by whyf on 2021/10/9.
//

#import "BaseManager.h"

typedef NS_ENUM(NSUInteger, WBMarkToolType) {
    WbMarkToolType_None,     // 无选中的工具
    WbMarkToolType_PenCil,   // 画笔
    WbMarkToolType_Eraser    // 橡皮擦
};

typedef NS_ENUM(NSUInteger, WBFileType) {
    WBFileType_Dir = 0,    // 子文件夹
    WBFileType_Normal,     // 普通文档
    WBFileType_WhiteBoard, //白板文档
    WBFileType_Web,        //WEB文档
    WBFileType_WbRoot      // 文档根目录
};

NS_ASSUME_NONNULL_BEGIN

@class WhiteBoardView;

@interface WhiteBoardManager : BaseManager
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<WhiteBoardManagerDelegate>) listener;
/**
 * 创建白板
 *
 * @param filePath   白板文档名称
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)createWhiteBoard:(NSString *)filePath;

/**
 * 停止共享
 *
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)stopShareWhiteBoard;

/**
 * 关闭他人屏幕共享
 *
 * @param userID   屏幕共享者的ID
 * @param dataType   屏幕共享类型
 * @param rightsIndex   权限索引
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)closeOtherVNC:(unsigned long)userID dataType:(_DataType)dataType rightsIndex:(int)rightsIndex;

/**
 * 获取当前版本数量
 *
 * @return NSInteger    白板个数
 */
-(NSInteger)getWhiteBoardCount;

/**
 * 获取当前激活的白板视图
 *
 * @return WhiteBoardView    白板视图对象
 */
-(WhiteBoardView *)getCurActiveWhiteBoard;

/**
 * 获取当前激活且要标注的白板，与上个接口的差别是此接口内部判断了用户标注的权限
 *
 * @return WhiteBoardView    标注的白板视图对象
 */
-(WhiteBoardView *)getMarkWhiteBoard;

/**
 * 通过ID，类型获取白板
 *
 * @param wbId   白板ID
 * @param dataType   屏幕共享类型
 * @return WhiteBoardView    白板视图对象
 */
-(WhiteBoardView *)getWhiteBoardByID:(unsigned long)wbId dataType:(_DataType)dataType;

/**
 * 开始标注白板
 *
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)startMarkWhiteBoard;

/**
 * 获取当前画笔颜色
 *
 * @return UIColor    返回当前画笔颜色
 */
-(UIColor *)getCurrentPenColor;

/**
 * 设置当前画笔颜色
 *
 * @param color   颜色值
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setCurrentPenColor:(UIColor *)color;

/**
 * 设置白板标注工具
 *
 * @param markToolType   标注工具类型
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setWbMarkTool:(WBMarkToolType)markToolType;

/**
 * 结束标注
 *
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)stopMarkWhiteBoard;

/**
 * 获取所有的白板视图对象
 *
 * @return NSMutableArray<WhiteBoardView*>    白板视图对象数组
 */
-(NSMutableArray<WhiteBoardView*>*)getWhiteBoardList;

/**
 * 设置数据区域当前是否处于缩略图页面
 *
 * @param isThumbing   是否是缩略图页面
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setWhiteBoardIsThuming:(BOOL)isThumbing;

/**
 * 是否处于缩略图页面
 *
 * @return BOOL    是否在缩略图页面
 */
-(BOOL)whiteBoardIsThuming;

/**
 * 设置白板是否可以标注
 *
 * @param isCanMark   是否可以标注
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setWhiteBoardIsCanMark:(BOOL)isCanMark;

/**
 * 是否显示缩略图的关闭按钮
 *
 * @param blockView   要显示的关闭按钮的白板视图对象
 * @return BOOL    是否显示关闭按钮
 */
-(BOOL)isHidedenThumingCloseBtn:(WhiteBoardView *)blockView;

/**
 * 是否显示屏幕共享缩略图关闭按钮
 *
 * @return BOOL    是否显示关闭按钮
 */
-(BOOL)isHiddenVNCThumingDeleteBtn;

/**
 * 激活某个白板
 *
 * @param activeWbView   要激活的白板视图对象
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)ActiveTheWhiteBoard:(WhiteBoardView *)activeWbView;

/**
 * 旋转白板
 *
 * @param nAngle   要旋转的角度值
 * @return void    无返回值
 */
- (void)setRotateAngle:(NSInteger)nAngle;

/**
 * 获取保存白板的图片
 *
 * @param view   要保存的白板视图对象
 * @return UIImage    白板图片
 */
-(UIImage *)getSaveWhiteBoardImage:(WhiteBoardView *)view;

//获取会中文档列表 暂不提供
//-(NSArray *)getRoomFileList;

//打开会中在线文档 暂不提供
//-(ReturnCode)openRoomFile:(FileListItemObj *)fileName;

/**
 * 获取会中多人共享个数
 *
 * @return NSInteger    会中允许多人共享的个数
 */
-(NSInteger)getMeetingRoomSharedUserCount;

/**
 * 会议是否可以多人共享
 *
 * @return BOOL    会中是否可以多人共享
 */
-(BOOL)enableMeetingMultiDataSharer;

/**
 * 获取会中白板数据块列表
 *
 * @return NSArray<DataBlockObj *>    白板数据块对象列表
 */
-(NSArray<DataBlockObj *>*)getWhiteBoardDataList;

/**
 * 获取当前激活的白板数据块对象
 *
 * @return DataBlockObj    白板数据块对象
 */
-(DataBlockObj *)getActiveDataBlock;

/**
 * 是否在标注页面
 *
 * @return BOOL   是否正在标注
 */
-(BOOL)isInMarkingVC;

/**
 * 设置本地激活的数据类型
 *
 * @param dataType   数据类型
 * @return ReturnCode   返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setLocalDataActiveType:(_DataType)dataType;

/**
 * 设置本地激活白板的位置
 *
 * @param pos   位置index
 * @return ReturnCode   返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setLocalDataActiveObjPos:(int)pos;

/**
 * 发送白板激活消息到远端
 *
 * @param wbID   白板ID
 * @return ReturnCode   返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)sendWBActiveInfo2Remote:(unsigned int)wbID;

/**
 * 通过白板数据对象激活白板
 *
 * @param blockObj   白板数据块
 * @return ReturnCode   返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setLocalActiveWBObjWithblockObj:(DataBlockObj *)blockObj;

/**
 * 每次激活白板后都需要重绘
 *
 * @param currentWBView   需要刷新的白板视图对象
 * @return void  无返回值
 */
-(void)reloadCurrentPage:(WhiteBoardView *)currentWBView;

/**
 * 清空本地白板视图数据缓存
 *
 * @return ReturnCode   返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)clearLocalWBViewCache;
@end

NS_ASSUME_NONNULL_END
