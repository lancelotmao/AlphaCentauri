//
//  Widget.h
//  mWidget
//
//  Created by Nil on 19/10/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <UIKit/UIKit.h>
#import "MRJSExecutor.h"
@protocol WidgetExport <JSExport>
- (void)alert :(NSString *)message;
- (void)toast :(NSString *)message :(NSDictionary *)content;
- (void)showConfirmDialog:(NSString *)title :(NSDictionary *)content :(JSValue*)cancelFunc :(JSValue *)okFunc;
- (void)showTimePickerDialog :(NSString *)title :(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)otherButton;
- (void)showDatePickerDialog :(NSString *)title :(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)okButton;
- (void)showNumberPickerDialog :(NSString *)title  :(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)okButton;
- (void)showPickerViewDialog:(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)okButton;
- (void)showProgressDialog:(NSString *)title :(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)okButton;
- (void)showLoading:(NSArray *)images;
- (void)showLoadingWithCancel:(NSArray *)images;

- (void)showSingleChooserDialog:(NSString *)title :(NSDictionary *)otherContent :(JSValue *)cancelButton :(JSValue *)okButton;
- (void)showMultiChooserDialog :(NSString *)title :(NSDictionary *)contentDic :(JSValue *)cancelButton :(JSValue *)okButton;
- (id)sendNotification:(NSString *)fireData :(NSDictionary *)notificationDic;
- (id)showPopupMenu:(NSString *)atViewId :(NSArray *)items :(NSString *)backgroundColor :(NSString *)rowHeight :(JSValue *)callbackFun;
- (void)showPopupView:(NSString *)smartLayoutID :(NSString *)buttonID :(NSString *)grivaty;

- (void)dismissLoading;
- (void)dismissPopupView;
- (void)dismissPopupMenu;
- (void)updateProgress:(float)progress;

@end

@interface Widget : NSObject<WidgetExport>
@property (nonatomic,weak)MRJSExecutor *jsExcutor;


@end
