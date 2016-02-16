//
//  MRTimerPickerDialog.h
//  MRAPI
//
//  Created by rossyang on 15/3/20.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

//tip: this method deprecated

#import "Dialog.h"

@interface MRTimerPickerDialog : Dialog
- (void)showTimePickerDialog :(NSString *)title :(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)otherButton;

-(instancetype)initWithTitle:(NSString *)title andOKButton:(JSValue *)okButton andCancelButton:(JSValue *)cancelButton andNowtime:(NSString *)nowtime andMaxtime:(NSString *)maxtime andMintime:(NSString *)mintime ;

-(instancetype)initWithTitle:(NSString *)title andNowTime:(NSString *)nowTime andFormat:(NSString *)format andCancelButtonTitle:(JSValue *)cancelButton andOtherButton:(JSValue *)otherButton andID:(NSString *)ID;
@end
