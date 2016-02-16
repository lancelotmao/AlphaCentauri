//
//  MRDialog.h
//  MRAPI
//
//  Created by chengxinqing on 15/3/19.
//  Copyright (c) 2015年 huawei. All rights reserved.
//


#import <JavaScriptCore/JavaScriptCore.h>
#import "MRView.h"
@class Dialog;
@protocol MRDialogExport <JSExport>

- (void)setOKCallbackForJS:(JSValue *)jsFunction;

@end
@interface MRDialog : MRView<MRDialogExport>
typedef NS_ENUM(NSUInteger, MRDialogShowPositon) {
    MRDialogShowPositonTop,
    MRDialogShowPositonCenter,
    MRDialogShowPositonBottom
};
@property(nonatomic,readonly)Dialog *dialog;
@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, assign) BOOL dismissAuto;
//@property (nonatomic, assign) DialogShowPositon showPositon;
@property (nonatomic, assign, readonly) BOOL isVisible;
@property (nonatomic, strong) NSString *identifier;

@property (nonatomic,weak) JSValue *jsFunction;

- ( instancetype )initWithTitle:(NSString *)title;
- ( instancetype )initWithTitle:(NSString *)title contentView:(UIView *)contentView;
- ( instancetype )initWithTitle:(NSString *)title contentView:(UIView *)contentView showPosition:(MRDialogShowPositon) positon;
- ( void ) addFirstButtonWithTitle:(NSString *)title andEvent:(NSString *)jscode;
- ( void ) addMiddleButtonWithTitle:(NSString *)title andEvent:(NSString *)jscode;
- ( void ) addLastButtonWithTitle:(NSString *)title andEvent:(NSString *)jscode;
- (void)setOKCallbackForJS:(JSValue *)jsFunction;

- (void)show;
- (void)dismiss;

@end
