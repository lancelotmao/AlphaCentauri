//
//  MRAlertDialog.h
//  mWidget
//
//  Created by zhouguoqiang on 14/12/18.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "MRView.h"
#import <JavaScriptCore/JavaScriptCore.h>

@interface MRAlertDialog : MRView

- (void)showProgressDialog:(NSString *)title :(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)okButton;
- (void)showSingleChooserDialog:(NSString *)title :(NSDictionary *)otherContent :(JSValue *)cancelButton :(JSValue *)okButton;
- (void)showMultiChooserDialog :(NSString *)title :(NSDictionary *)contentDic :(JSValue *)cancelButton :(JSValue *)okButton;
- (void)updatepProgress:(float)progress;

@end
