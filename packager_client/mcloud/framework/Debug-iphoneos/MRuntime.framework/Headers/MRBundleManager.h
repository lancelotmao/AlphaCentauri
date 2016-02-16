//
//  MRBundleManager.h
//  MRuntime
//
//  Created by lucaiguang on 14-10-23.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

#import "MRContext.h"
#import "MRBusAccess.h"

extern BOOL downloadBundleFlag; //控制是否通过网络下载bundle

@class MRBundleInfo;
@interface MRBundleManager : NSObject <MRBundleProviderDelegate, MRContextDelegate>
@property (nonatomic, strong, readonly) NSDictionary *localBundles;
//@property (nonatomic, strong, readonly) NSDictionary *loadedBundles;
//@property (nonatomic, strong, readonly) NSArray *queryOnlineBundles;

@property (nonatomic, strong) MRContext *context;
@property (nonatomic, assign) BOOL isStudio;
@property (nonatomic, strong) UIViewController *rootViewController;

- (void)autoLoginTimer;

- (void)autoLoginReset;

+ (MRBundleManager *)shareInstance;

- (void)loadBundle:(MRBundleInfo *)bundleInfo;

- (void)startBundle:(MRBundleInfo *)bundleInfo;

- (void)stopBundle:(MRBundleInfo *)bundleInfo;
- (void)pauseAllBundles;
- (void)resumeAllBundles;
- (void)unloadBundle:(MRBundleInfo *)bundleInfo;
- (NSMutableDictionary *)searchLocalBundle;

#pragma mark - MAM
- (void)checkBundleVersion;

#pragma mark -
/**
 *  bundle zip文件登记。
 *
 *  @param zipfile bundle zip文件
 *  @param isLoad  是否加载bundle进内存
 *  @param error   错误信息
 *
 *  @return 登记成功
 */
- (BOOL)registry:(NSString *)zipfile loadBundle:(BOOL)load errorInfo:(NSError *__autoreleasing *)error;

- (BOOL)downloadBundleWithBundleName:(NSString *)bundleName loadBundle:(BOOL)isLoad;
- (NSString *)magUrl:(BOOL)uniportal;
@end
