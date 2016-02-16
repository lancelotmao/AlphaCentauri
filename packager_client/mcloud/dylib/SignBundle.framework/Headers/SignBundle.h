//
//  SignBundle.h
//  SignBundle
//
//  Created by ywx272253 on 15/9/15.
//  Copyright (c) 2015年 com.huawei.hwcloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MRuntime/MRuntime.h>

//! Project version number for SignBundle.
FOUNDATION_EXPORT double SignBundleVersionNumber;

//! Project version string for SignBundle.
FOUNDATION_EXPORT const unsigned char SignBundleVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SignBundle/PublicHeader.h>


@interface SignBundle : MRBundleBase

/*
 attribute的格式:
 {
 strokeWidth:画笔大小
 strokeColor:画笔颜色
 style:样式
 {
 buttonTextColor:button颜色
 buttonBackground:button背景
 background:背景
 closeButton: 关闭按钮
 signBackgroundColor:画布背景
 }
 }
 */
- (void)signForJS:(NSDictionary *)attribute :(JSValue *)cb;

- (void)sign:(NSDictionary *)attribute :(void(^)(NSDictionary *))cb;

@end

