//
//  MRBundle.h
//  MRuntime
//
//  Created by lucaiguang on 14-10-21.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MRBundleBase;
@interface MRBundleInfo : NSObject
@property (nonatomic, copy) NSString *bundleIdentifier; //bundle唯一标识
@property (nonatomic ,copy) NSString *bundleAlias;//bundle 别名
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *icon;
@property (nonatomic, assign) unsigned long long size;
@property (nonatomic, copy) NSString *remoteUrl; //远程地址
@property (nonatomic, copy) NSString *localUrl; //本地地址
@property (nonatomic, assign) int versionCode; //版本码
@property (nonatomic, copy) NSString *version; //版本号
@property (nonatomic, assign) int bundleOrder; //bundle在installed中的顺序。
@property (nonatomic, assign) int availableVersionCode; //最近从服务器取得的版本码
@property (nonatomic, copy) NSString *availableVersion; //最近从服务器取得的版本号
@property (nonatomic, copy) NSString *des;
@property (nonatomic, copy) NSString *bundleType;
@property (nonatomic, strong) MRBundleBase *plugin;
@property (nonatomic, copy) NSString *aClass;//principal Class
@property (nonatomic, assign) NSBundle *bundle;
@property (nonatomic, strong) NSArray *dependencies;
@property (nonatomic ,strong) NSString *descriptions;
@property (nonatomic, assign) unsigned long long downloadCount;
@property (nonatomic,assign) BOOL isUpdate;
@property (nonatomic,assign) BOOL isDownload;
@property (nonatomic,assign) BOOL isOn;
-(NSMutableArray *)creatBundleInfoWithdata:(NSArray *)array ;
@end
