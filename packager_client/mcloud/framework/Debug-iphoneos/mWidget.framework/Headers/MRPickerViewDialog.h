//
//  MRPickerViewDialog.h
//  mWidget
//
//  Created by hushengcai on 15/11/12.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import <mWidget/mWidget.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol MRPickerViewDialogExport <JSExport>

- (void)setOKCallbackForJS:(JSValue *)jsFunction;
- (void)setCancelCallbackForJS:(JSValue *)jsFunction;

@end

@interface MRPickerViewDialog : Dialog

- (void)showPickerViewDialog:(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)okButton;

-(instancetype)initWithTitle:(NSString *)title  Type:(NSString *)type MinValue:(NSString *)minValue MaxValue:(NSString *)maxValue DefaultValue:(NSString *)defaultValue Values:(NSString *)values CancelButton:(JSValue *)cancelButton OtherButton:(JSValue *)otherButton;

@end
