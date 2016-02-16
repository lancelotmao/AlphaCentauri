//
//  MRConfigTools.h
//  MRConfigBundle
//
//  Created by rossyang on 14/11/20.
//  Copyright (c) 2014年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@interface MRConfigTools : NSObject

+ (MRConfigTools *)shareInstance;

- (void)loadConfigureInfo:(NSString *)packageName;

- (NSString *)getValueFromConfig:(NSString *) packageName key:(NSString *) key;

- (NSDictionary *)getMultiValuesFromConfig:(NSString *)packageName key:(NSArray *) keys;

- (NSString *)getLoginUrl:(NSString *)packageName;

- (NSString *)getUpgradeUrl:(NSString *)packageName;

- (NSString *)getBindDivUrl:(NSString *)packageName;

- (NSString *)getFeedbackUrl:(NSString *)packageName;

- (NSString *)getInsightUrl:(NSString *)packageName;

- (NSString *)getW3UpdateUrl:(NSString *)packageName;

- (NSString *)getChangePwdUrl:(NSString *)packageName;

- (BOOL)setPrivateValue:(NSString *)packageName key:(NSString *)key value:(NSString *)value;
- (BOOL)removePrivateValue:(NSString *)packageName key:(NSString *)key;
- (id)getPrivateValue:(NSString *)packageName key:(NSString *)key defalutValue:(NSString *)defValue;
- (BOOL)removeAllPrivateValue:(NSString *)packageName;
- (NSString *)createCommonValue:(NSString *)key value:(id)value;
- (id)getCommonValue:(NSString *)key;
- (NSString *)updateCommonValue:(NSString *)key value:(JSValue *)value;
@end
