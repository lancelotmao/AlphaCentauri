//
//  MRBundleTool.h
//  MRuntime
//
//  Created by lucaiguang on 14-10-21.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

/**
 *  专门管理已下载的Bundle
 */
#import <Foundation/Foundation.h>
#import "MRBundleInfo.h"

@interface MRBundleTool : NSObject

+ (MRBundleTool *)shareInstance;

@property (nonatomic, strong, readonly) NSDictionary *shareDictionary;

@property (nonatomic, strong, readonly) NSArray *shareArray;

@property (nonatomic, strong, readonly) NSArray *appArray;

- (BOOL)addBundle:(MRBundleInfo *)bundle;

- (BOOL)addBundles:(NSArray *)bundleArray;

- (BOOL)deleteBundle:(MRBundleInfo *)bundle;

- (BOOL)updateBundle:(MRBundleInfo *)bundle;

- (BOOL)unZipWithBundle:(MRBundleInfo *)bundle;

@end
