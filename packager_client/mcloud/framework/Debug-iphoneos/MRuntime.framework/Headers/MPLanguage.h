//
//  MPLanguage.h
//  mjet
//
//  Created by lucaiguang on 14/11/11.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LANGUAGE(key) [[MPLanguage shareInstance] localizedStringForKey:key]

//Notification
#define kLanguageChange @"kLanguageChange"

@interface MPLanguage : NSObject

// 支持的语言
@property (nonatomic, strong, readonly) NSArray *availableLanguagesArray;

// 是否保存设置
@property (nonatomic, assign) BOOL saveInUserDefaults;

// 当前语言
@property (nonatomic, strong, readonly) NSString *currentLanguage;

+ (MPLanguage *)shareInstance;

/**
 *  获取本地化字符串。 使用上面定义的宏，便捷获取本地化字符串
 */
- (NSString *)localizedStringForKey:(NSString *)key;

/**
 *  设置语言。默认为中文。语言改变成功会发送通知（kLanguageChange）
 */
- (BOOL)setLanguage:(NSString *)newLanguage;

@end
