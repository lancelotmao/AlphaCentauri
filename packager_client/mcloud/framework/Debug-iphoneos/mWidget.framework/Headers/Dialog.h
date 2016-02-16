//
//  MRDialog.h
//  MRAPI
//
//  Created by rossyang on 14/12/31.
//  Copyright (c) 2014年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol DialogExport <JSExport>

- (void)setOKCallbackForJS:(JSValue *)jsFunction;
- (void)setCancelCallbackForJS:(JSValue *)jsFunction;
@end

typedef NS_ENUM(NSUInteger, DialogShowPositon) {
    DialogShowPositonTop,
    DialogShowPositonCenter,
    DialogShowPositonBottom
};

@interface Dialog : UIView <DialogExport>

@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, assign) BOOL dismissAuto;
@property (nonatomic, assign) DialogShowPositon showPositon;
@property (nonatomic, assign, readonly) BOOL isVisible;
@property (nonatomic, strong) NSString *identifier;
//@property (nonatomic, assign) UIEdgeInsets contentViewEdge;

@property (nonatomic, strong) NSObject *observer;

- (void)show;
- (void)dismiss;
- ( instancetype )initWithTitle:(NSString *)title;
- ( instancetype )initWithTitle:(NSString *)title contentView:(UIView *)contentView;
- ( instancetype )initWithTitle:(NSString *)title contentView:(UIView *)contentView showPosition:(DialogShowPositon) positon;

- ( void ) addFirstButtonWithTitle:(NSString *)title andEvent:(NSString *)jscode;
- ( void ) addMiddleButtonWithTitle:(NSString *)title andEvent:(NSString *)jscode;
- ( void ) addLastButtonWithTitle:(NSString *)title andEvent:(NSString *)jscode;

//- ( void )setOKCallback:(NSString *)jsfunc;
@end

@interface MRDialogButton : NSObject

@property (nonatomic, strong) UIButton *button;
@property (nonatomic, strong) NSString *event;
@property (nonatomic, assign) CGFloat buttonWidth;

@end
