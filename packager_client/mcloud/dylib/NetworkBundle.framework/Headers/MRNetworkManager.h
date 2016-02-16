//
//  MRNetworkManager.h
//  MRNetwork
//
//  Created by lucaiguang on 15/4/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MRuntime/MRuntime.h>

@class JSValue;
@interface MRNetworkManager : NSObject

@property (nonatomic, copy, readonly) NSString *networkStatus;

+ (MRNetworkManager *)shareInstance;

- (NSString *)getAvailableNetwork;

- (BOOL)isNetworkAvailable;

- (BOOL)isMobileNetwork;

- (void)addNetworkMonitorWithTarget:(id)aObject method:(SEL)function;

- (void)removeNetworkMonitorWithTarget:(id)aObject method:(SEL)function;

- (NSDictionary *)login:(NSString *)url head:(NSDictionary *)head body:(NSDictionary *)body;

- (NSDictionary *)logout:(NSString *)url head:(NSDictionary *)head body:(NSDictionary *)body;

- (NSDictionary *)httpGet:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head;

- (NSDictionary *)httpPost:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head body:(NSString *)body;

- (NSDictionary *)httpPut:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head body:(NSString *)body;

- (NSDictionary *)httpDelete:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head;

- (NSDictionary *)httpForm:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head body:(NSDictionary *)body;

- (NSString *)addNetworkSpeedMonitor:(void(^)(NSArray *))callback;
- (void)removeNetworkSpeedMonitor:(NSString *)speedID :(void(^)(NSArray *))callback;
- (void)removeAllNetworkSpeedMonitor:(void(^)(NSArray *))callback;

#pragma mark - For JS

- (id)addNetworkMonitorForJS:(JSValue *)callback;

- (NSNumber *)removeNetworkMonitorForJS:(JSValue *)callback :(NSString *)callbackKey;

- (void)removeAllNetworkMonitorForJS:(JSValue *)callback;

- (void)getAvailableNetworkForJS:(JSValue *)callback;

- (BOOL)isNetworkAvailableForJS:(JSValue *)callback;

- (BOOL)isMobileNetworkForJS:(JSValue *)callback;

//- (NSDictionary *)loginForJS:(NSString *)url head:(NSDictionary *)head body:(NSDictionary *)body jsCallBack:(JSValue *)jsFunction;
//
//- (NSDictionary *)logoutForJS:(NSString *)url head:(NSDictionary *)head body:(NSDictionary *)body jsCallBack:(JSValue *)jsFunction;

- (NSDictionary *)httpGetForJS:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head jsCallBack:(JSValue *)jsFunction;

- (NSDictionary *)httpPostForJS:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head body:(NSString *)body jsCallBack:(JSValue *)jsFunction;

- (NSDictionary *)httpPutForJS:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head body:(NSString *)body jsCallBack:(JSValue *)jsFunction;

- (NSDictionary *)httpDeleteForJS:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head jsCallBack:(JSValue *)jsFunction;

- (NSDictionary *)httpFormForJS:(NSString *)url param:(NSString *)param needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head body:(NSDictionary *)body jsCallBack:(JSValue *)jsFunction;

// add network speed to keep been consistent with Android
//began
-(NSString *)addNetworkSpeedMonitorForJS:(JSValue *)jsFunction;
-(void)removeNetworkSpeedMonitorForJS:(NSString *)monitorID :(JSValue *)jsFuncyion;
-(void)removeAllNetworkSpeedMonitorForJS:(JSValue *)jsFunction;
//end


#pragma mark - multi users
- (NSDictionary *)multiUserLogin:(NSString *)url head:(NSDictionary *)head body:(NSDictionary *)body identifier:(NSString *)identifier;

- (NSDictionary *)multiUserRequest:(NSString *)method url:(NSString *)url needLogin:(NSNumber *)needLogin isEncrypt:(NSNumber *)isEncrypt head:(NSDictionary *)head body:(id)body identifier:(NSString *)identifier;
@end
