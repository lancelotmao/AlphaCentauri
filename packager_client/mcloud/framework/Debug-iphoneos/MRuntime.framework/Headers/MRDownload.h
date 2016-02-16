//
//  MRDownload.h
//  downFileTest
//
//  Created by rossyang on 14/11/3.
//  Copyright (c) 2014年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MRBundleInfo;
@interface MRDownload : NSObject


/*
 当文件名相同时是否覆盖,overwriter为NO的时候，当文件已经存在，则下载结束
 */
@property (nonatomic, assign) BOOL overwrite;
/*
 下载的地址,当下载地址为nil，下载失败
 */
@property (nonatomic, strong) MRBundleInfo *info;
/*
 下载文件的名字名，默认为下载原文件名
 */
@property (nonatomic, strong) NSString *fileName;
/*
 文件保存的path(不包括文件名),默认路径为DocumentDirectory
 */
@property (nonatomic, strong) NSString *filePath;
/*
 下载的大小,只有当下载任务成功启动之后才能获取
 */
@property (nonatomic, readonly) unsigned long long fileSize;

/*
 
*/
@property (nonatomic, strong) void (^progressHandler)(float value);
@property (nonatomic, strong) void (^completeHandler)(float value, NSError *error);


- (void)start;              //开始下载
- (void)stop;               //停止下载
- (void)stopAndClear;       //停止清理(己下载完成的或缓存)
- (id)initWithMRBundle:(MRBundleInfo *)info;
//- (void)startWithHandler:(void(^)(float value))progressHandler andCompleteHandler:(void(^)(float value, NSError *error))completeHandler;


@end
