//
//  TalkingData.h
//  TalkingData
//
//  Created by qingyun on 12/25/14.
//  Copyright (c) 2014 qingyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#define kTDSDKVersion @"iOS+BFAnalyticsData+V1.1.0"

//用户信息
/*********************************************************************************************************/
@interface BFUserInfo : NSObject<NSCoding>

@property (nonatomic, retain)NSString *userName;                // # 登录用户
@property (nonatomic, retain)NSString *userType;                // # 账号类型  例如：边锋、QQ、新浪等
@property (nonatomic, retain)NSString *userId;                  // # 数字账号 （可选）
@property (nonatomic, retain)NSString *UserAreaName;            // # 区服名   （可选）
@property (nonatomic, assign)int       userLev;                 // # 用户等级 （可选）
@property (nonatomic, retain)NSString *userVipLev;              // # 用户等级 （可选）

+(BFUserInfo*)shareUserInfo;

@end



//支付信息
/*********************************************************************************************************/
@interface BFPurchaseInfo : NSObject

@property (nonatomic, assign)double    payPrice;                // # 登录用户
@property (nonatomic, retain)NSString *payOrderId;              // # 订单号
@property (nonatomic, retain)NSString *payType;                 // # 支付类型
@property (nonatomic, assign)double    paycardValue;            // # 卡面值


+(BFPurchaseInfo*)sharePurchaseInfo;

@end


//充值货币进出参数
/*********************************************************************************************************/
@interface BFItemInfo : NSObject

@property (nonatomic, assign)int      itemNum;                  // # 物品数量
@property (nonatomic, retain)NSString *itemType;                // # 物品种类
@property (nonatomic, retain)NSString *itemName;                // # 物品种类
@property (nonatomic, retain)NSString *itemId;                  // # 物品ID


@end

//设备信息
/*********************************************************************************************************/
@interface BFDeviceInfo : NSObject

+ (NSString *)getDeviceId;
+ (NSString *)getDeviceType;
//+ (NSString *)getDeviceVersionCode;
+ (NSString *)getDeviceOS;
+ (NSString *)getDeviceMobile;
+ (NSString *)getDeviceOsVer;
+ (NSString *)getDevicePixel;
+ (NSString *)getDeviceNetwork;
+ (NSString *)getDeviceCarrier;
+ (NSString *)getAppVersionName;
+ (NSString *)getAppVersionCode;
@end


@interface BFAnalyticsData : NSObject

+(BFAnalyticsData*)shareData;

//基本功能
/**
 *	@method	sessionStarted:withChannelId:
 *  初始化统计实例，请在application:didFinishLaunchingWithOptions:方法里调用
 *	@param 	appKey          应用的唯一标识，统计后台注册得到
 *  @param 	channelId(可选) 	渠道名，如“app store”
 *  @param  groupID         平台id，没有平台概念就写0
 */
//onstart
+ (void)onStartedWithAppKey:(NSString *)appKey withChannelId:(NSString *)channelId withGroupId:(NSString*)groupId;


/**
 *	@method	setCustomEvent:
 *  自定义统计实例，
 *	@param 	eventId             事件名称（自定义）
 *  @param 	eventLabel          事件标签（自定义）
 *  @param  parameters(可选)     事件参数 (key只支持NSString, value支持NSString和NSNumber)
 *  @param  num
 */
//double  value    计次事件(无value ) 计值事件(有value)
+ (void)setCustomEvent:(NSString *)eventId withLabel:(NSString *)eventLabel parameters:(NSDictionary *)parameters :(int)num;


/**
 *	@method	onRegister:
 *  注册
 *  @param 	userInfo           注册时需要设置userInfo里的 userName  userType（userId可选）
 */
+ (void)onRegister:(BFUserInfo*)userInfo;


/**
 *	@method	onLogin:
 *  登录
 *  @param 	userInfo           登录时需要设置userInfo里的 userName  userType（其它选填）
 */
+ (void)onLogin:(BFUserInfo*)userInfo;


/**
 *	@method	onLogin:
 *  在线时长，从游戏登录到退出的这个时间差
 */
+ (void)logout;


/**
 *	@method	onPurchase:
 *  支付
 *  @param 	purchaseInfo
 */
+ (void)onPurchase:(BFPurchaseInfo*)purchaseInfo;

/**
 *	@method	getCurrencyWithType:
 *  用户信息更新
 *  @param 	userInfo       当用户信息有变化时，上传用户信息
 */
+(void)updataUserInfo:(BFUserInfo*)userInfo;


//高级功能
/**
 *	@method	getCurrencyWithType:
 *  货币获得
 *  @param 	type           如、赠送，剧情掉落，通关奖励等
 *  @param 	amount         游戏充值获得的货币（例如元宝），包含系统获得货币，如果通关赠送了10个元宝，amount填10
 */
+ (void)getCurrencyWithType:(NSString *)type withAmount:(int)amount;


/**
 *	@method	consumeCurrencyWithType:
 *  消耗货币
 *  @param 	type           如、赠送，剧情掉落，通关奖励等
 *  @param 	amount         消耗的货币（例如元宝），如果消耗10个元宝 amount填10
 *  @param 	itemInfo
 */
+ (void)consumeCurrencyWithType:(NSString *)type withAmount:(int)amount  withItemType:(BFItemInfo*)itemInfo;


/**
 *	@method	getItem
 *  获得物品  例如玩家打通关卡送了100个木头，则itemInfo这个类里的 type为通关奖励，itemName为木头， itemNum为100
 *  @param 	itemInfo
 */
+ (void)getItem:(BFItemInfo*)itemInfo;


/**
 *	@method	consumeItem:
 *  消耗物品 如果消耗一个喇叭，则itemInfo这个类里的  itemName喇叭，consume填1
 *  @param 	itemInfo
 */
+ (void)consumeItem:(BFItemInfo*)itemInfo;


/**
 *	@method	setExceptionReportEnabled
 *  是否捕捉程序崩溃记录 (可选)
 *	@param 	enable 	默认是YES
 如果需要自行记录程序崩溃日志，请将值设成NO，并且在调用sessionStarted:withChannelId:之前调用此函数
 */
+ (void)setExceptionReportEnabled:(BOOL)enable;


/**
 *	@method	setLogEnabled
 *  统计日志开关（可选）
 *	@param 	enable 	默认是开启状态
 */
+ (void)setLogEnabled:(BOOL)enable;

/**
 *	@method	setLatitude:longitude:
 *  设置位置信息（可选）
 *	@param 	latitude 	维度
 *	@param 	longitude 	经度
 */
+ (void)setLatitude:(double)latitude longitude:(double)longitude;


/**
 *	@method	trackPageBegin
 *  开始跟踪某一页面（可选），记录页面打开时间
 建议在viewWillAppear或者viewDidAppear方法里调用
 *	@param 	pageName 	页面名称（自定义）
 */
+ (void)trackPageBegin:(NSString *)pageName;

/**
 *	@method	trackPageEnd
 *  结束某一页面的跟踪（可选），记录页面的关闭时间
 此方法与trackPageBegin方法结对使用，
 建议在viewWillDisappear或者viewDidDisappear方法里调用
 *	@param 	pageName 	页面名称，请跟trackPageBegin方法的页面名称保持一致
 */
+ (void)trackPageEnd:(NSString *)pageName;


+(NSString*)getDeviceAddr;


@end
