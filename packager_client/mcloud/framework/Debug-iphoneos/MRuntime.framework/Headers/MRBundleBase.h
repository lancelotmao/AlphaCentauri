//
//  MRBundleBase.h
//  MRuntime
//
//  Created by lucaiguang on 14-10-22.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

#import "MRContext.h"

@protocol MRuntimeDelegate <NSObject>
- (BOOL)callback:(NSDictionary*)param;
@end

@interface MRBundleBase : NSObject

@property (nonatomic, weak) id<MRuntimeDelegate> runtimeDelegate;

// 每次Bundle被载入的时候都会被调用，无论bundle是lib还是app
- (void)onLoad:(MRContext *)context;

// 只有用户在Installed列表上点击图标的时候才会调用
- (void)onCreate:(MRContext *)context;

// Bundle从后台切换至前台时调用
- (void)onResume;

// bundle切换至后台时调用
- (void)onPause;

// Bundle退出前调用，Bundle需要在这里停掉线程，释放资源和内存
// 如果已经释放所有资源返回YES，否则返回NO。假如返回了NO，Bundle Mananger
// 会在未来的某时刻再次尝试停掉该Bundle
- (BOOL)willDestroy;

// Bundle退出的时候调用
- (void)onDestory;

- (BOOL)isAndroidCompatible;
@end
