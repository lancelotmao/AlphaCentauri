//
//  MRNumberPickerDialog.h
//  MRAPI
//
//  Created by rossyang on 15/1/31.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

//tip: this method deprecated

#import "Dialog.h"
#import <JavaScriptCore/JavaScriptCore.h>

@protocol MRNumberPickerDialogExport <JSExport>

- (void)setOKCallbackForJS:(JSValue *)jsFunction;
- (void)setCancelCallbackForJS:(JSValue *)jsFunction;

@end

@interface MRNumberPickerDialog : Dialog
@property(nonatomic,strong,readonly)UIPickerView *MRPickerView;
-(instancetype)initWithTitle:(NSString *)title andMinNum:(NSString *)minNum andMaxNum:(NSString *)maxNum andDefaultNum:(NSString *)defaultNum andCancelButton:(JSValue *)cancelButton andOtherButton:(JSValue *)otherButton andID:(NSString *)ID;

- (void)showNumberPickerDialog :(NSString *)title  :(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)okButton;
@end
