//
//  MRContext.h
//  MRuntime
//
//  Created by lucaiguang on 14-10-22.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "ResourceManager.h"
#import "MRScript.h"
#import "Executor.h"

@protocol MRContextDelegate <NSObject>

- (void)startBundleWithBundleName:(NSString *)bundleName;

- (void)startViewController:(UIViewController *)viewController ;

- (void)stopViewController:(UIViewController *)viewController;

@end

@interface MRContext : NSObject

@property (nonatomic, weak) UIViewController *controller;
@property (nonatomic, weak) id<MRContextDelegate> delegate;
@property (nonatomic, strong) NSString* bundleName;// 当前bundle名
@property (nonatomic, strong) ResourceManager* resMan;
@property (nonatomic, weak) id<MRScriptExecutor> scriptExecutor;

// 启动
- (void)startViewController:(UIViewController *)viewController;

// 结束
- (void)stopViewController:(UIViewController *)viewController;

// 切换
- (void)switchViewController:(UIViewController *)viewConroller;

// 启动其他bundle的UI
- (void)startBundleWithBundleName:(NSString *)bundleName;

@end
