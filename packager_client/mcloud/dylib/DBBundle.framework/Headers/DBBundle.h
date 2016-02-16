//
//  DBBundle.h
//  DBBundle
//
//  Created by lucaiguang on 14/11/18.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

//! Project version number for DBBundle.
FOUNDATION_EXPORT double DBBundleVersionNumber;

//! Project version string for DBBundle.
FOUNDATION_EXPORT const unsigned char DBBundleVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <DBBundle/PublicHeader.h>

@protocol DBExport <JSExport>
JSExportAs(open, - (BOOL)openForJS:(NSString *)path :(JSValue *)callback);
JSExportAs(update, - (BOOL)updateForJS:(NSString *)sqlString);
JSExportAs(query, - (NSArray *)queryForJS:(NSString *)sqlString);
JSExportAs(execSQL, - (id)execSQLForJS:(NSString *)dbName sql:(NSString *)sqlString withCallback:(JSValue *)callbackFun);
JSExportAs(execQuery, - (id)execQueryForJS:(NSString *)dbName sql:(NSString *)sqlString withCallback:(JSValue *)callbackFun);
- (BOOL)close;
- (BOOL)beginTransaction;
- (BOOL)commit;
- (BOOL)rollback;
- (BOOL)inTransaction;
//- (void)callbackForJS:(JSValue *)jsFunction;
@end

@interface DBBundle : NSObject<DBExport>
/**
 *  打开数据库，如果没有则创建数据库。
 *
 *  @param path 数据库路径
 *
 *  @return 是否操作成功
 */
- (BOOL)open:(NSString *)path;

/**
 *  创建，插入，删除等操作
 *
 *  @param sqlString sql语句
 *
 *  @return 是否执行成功
 */
- (BOOL)update:(NSString *)sqlString;

/**
 *  查询数据库 //TODO:添加结果集
 *
 *  @param sqlString sql语句
 *
 *  @return 是否执行成功
 */
- (NSArray *)query:(NSString *)sqlString;

/**
 *  关闭数据库
 *
 *  @return 是否操作成功
 */
- (BOOL)close;

/**
 *  开始事务
 *
 *  @return 是否操作成功
 */
- (BOOL)beginTransaction;

/**
 *  开始事物延时
 *
 *  @return 是否操作成功
 */
- (BOOL)beginDeferredTransaction;

/**
 *  提交事务
 *
 *  @return 是否操作成功
 */
- (BOOL)commit;

/**
 *  事务回滚
 *
 *  @return 是否操作成功
 */
- (BOOL)rollback;

/**
 *  是否在事务中
 */
- (BOOL)inTransaction;

/**
 * executeForJS 辨析js传过来的操作
 */
- (id)execSQL:(NSString *)dbName sql:(NSString *)sqlString;
- (id)execQuery:(NSString *)dbName sql:(NSString *)sqlString;


#pragma mark - for js
//- (NSArray *)queryForJS:(NSString *)sqlString :(NSString *)path :(JSValue *)callback;
- (BOOL)openForJS:(NSString *)path :(JSValue *)callback;
- (BOOL)deleteForJS:(NSString *)path :(JSValue *)callback;
- (BOOL)updateForJS:(NSString *)sqlString;
- (NSArray *)queryForJS:(NSString *)sqlString;
- (id)execSQLForJS:(NSString *)dbName sql:(NSString *)sqlString withCallback:(JSValue *)callbackFun;
- (id)execQueryForJS:(NSString *)dbName sql:(NSString *)sqlString withCallback:(JSValue *)callbackFun;
@end
