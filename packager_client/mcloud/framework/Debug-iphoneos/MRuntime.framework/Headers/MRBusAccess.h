//
//  MRBusAccess.h
//  MRBusAccess
//
//  Created by lucaiguang on 14/10/27.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

#import <JavaScriptCore/JavaScriptCore.h>
#import <Foundation/Foundation.h>

#define MRBUS_ERROR_CODE_UNKNOWN -1

@interface MRBundleMethodResult : NSObject
@property (nonatomic, strong) id result;
@property int errorCode;
@end


typedef void (^BUNDLE_CALLBACK)(id, int);

typedef NS_ENUM(NSInteger, MRNetworkReachabilityStatus) {
    MRNetworkReachabilityStatusUnknown          = -1,
    MRNetworkReachabilityStatusNotReachable     = 0,
    MRNetworkReachabilityStatusReachable2G,
    MRNetworkReachabilityStatusReachable3G,
    MRNetworkReachabilityStatusReachable4G,
    MRNetworkReachabilityStatusReachableViaWiFi
};

extern NSString * const MRNetworkingReachabilityDidChangeNotification;
extern NSString * const MRNetworkingReachabilityNotificationStatusItem;

@interface MRBundleMethodProperty : NSObject

@property (nonatomic, assign) NSString *bundleName;
@property (nonatomic, assign) NSString *methodName;
@property (nonatomic, assign) NSArray *arguments;
@property (nonatomic, assign) MRBundleMethodResult *result;
@property (nonatomic, assign, readonly) BOOL syncMode;
@property (nonatomic, assign, readonly) BUNDLE_CALLBACK callback;
@property (nonatomic, assign, readonly) long timeout;

- (void)setSyncModeWithTimeout:(long)timeout;
- (void)setASyncModeWithCallback:(BUNDLE_CALLBACK)callback;

@end

@protocol MRBundleProviderDelegate <NSObject>
- (id)findAndLoadBundleWithSynchronizeMethod:(NSString *)bundleName;
- (void)findAndLoadBundleWithAsynchronizeMethod:(NSString *)bundleName callback:(BUNDLE_CALLBACK)callback;
@end

@class MRContext, JSValue;
@interface MRBusAccess : NSObject

@property (nonatomic, assign) id<MRBundleProviderDelegate> bundleProvider;
@property (nonatomic, strong) MRContext *context;
@property (nonatomic, assign) BOOL securityLock; //是否开启应用锁定, default is NO

+ (MRBusAccess *)shareInstance;

- (void)callNativeFunction:(MRBundleMethodProperty *)property;
- (void)callNativeFunctionAsync:(NSString *)bundleName withMethod:(NSString *)methodName withArguments:(NSArray *)arguments withCallback:(BUNDLE_CALLBACK)callback;
- (id)callNativeFunctionSync:(NSString *)bundleName withMethod:(NSString *)methodName withArguments:(NSArray *)arguments withTimeout:(long)timeout;

#pragma mark - bus for js
- (void)callNativeFunctionForJS:(MRBundleMethodProperty *)property withValue:(JSValue *)value;
- (void)callNativeFunctionAsyncForJS:(NSString *)bundleName withMethod:(NSString *)methodName withArguments:(NSDictionary *)arguments withValue:(JSValue *)value;
- (id)callNativeFunctionSyncForJS:(NSString *)bundleName withMethod:(NSString *)methodName withArguments:(NSDictionary *)arguments withValue:(JSValue *)value;

+ (id)createInstanceWithBundle:(NSString *)bundleName class:(NSString *)clsName;

@end