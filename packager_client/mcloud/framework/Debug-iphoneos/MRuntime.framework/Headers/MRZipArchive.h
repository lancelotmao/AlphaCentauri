//
//  MRZipArchive.h
//  MRuntime
//
//  Created by lucaiguang on 14/11/4.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SSZipArchiveDelegate;
@interface MRZipArchive : NSObject

/**
 *  文件解压
 *
 *  @param path        zip文件目录
 *  @param destination 解压文件目录
 *
 *  @return 是否解压成功
 */
+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination;

/**
 *  文件压缩
 *
 *  @param path          创建zip文件的目录 eg:@"/user/zip.zip"
 *  @param directoryPath 需要压缩文件的目录
 *
 *  @return 是否压缩成功
 */
+ (BOOL)createZipFileAtPath:(NSString *)path withContentsOfDirectory:(NSString *)directoryPath;




/****
* by:wxp
* 文件压缩
* @param path    文件被压缩到的目录
* @param paths   被压缩的文件
*/
+ (BOOL)createZipFileAtPath:(NSString *)path withFilesAtPaths:(NSArray *)paths;

/****
* by:wxp
* 文件解压
* @param path    存在有压缩文件的目录
* @param paths   压缩文件被压缩到的文件
*/
+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination delegate:(id<SSZipArchiveDelegate>)delegate;



@end
