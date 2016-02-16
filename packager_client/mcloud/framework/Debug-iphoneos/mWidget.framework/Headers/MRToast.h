//
//  MRToastView.h
//  UI
//
//  Created by mCloud on 14/12/5.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRView.h"

@interface MRToast : MRView<MRJSView>
@property (nonatomic, readonly) UILabel *label;

- (void)setToastWithMessage:(NSString *)message WithTimeDismiss:(NSString *)time;//双因子项目正在使用，暂时保留

- (void)setToastWithMessage:(NSString *)message WithDismissMode:(NSString *)mode :(NSString *)location :(NSString *)x :(NSString *)y;
- (void)showToast:(NSString *)title :(NSDictionary *)contentDic;
- (void)dissmiss;
@end
