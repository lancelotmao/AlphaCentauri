//
//  MRDatePickerDialog.h
//  MRAPI
//
//  Created by rossyang on 15/1/29.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

//tip: this method deprecated

#import "Dialog.h"
#import <JavaScriptCore/JavaScriptCore.h>
#import <MRuntime/MRuntime.h>

@protocol MRDatePickerDialogExport <JSExport>

- (void)setOKCallbackForJS:(JSValue *)jsFunction;
- (void)setCancelCallbackForJS:(JSValue *)jsFunction;


@end
@interface MRDatePickerDialog : Dialog
- (void)showDatePickerDialog :(NSString *)title :(NSDictionary *)content :(JSValue *)cancelButton :(JSValue *)okButton;

-(instancetype)initWithTitle:(NSString *)title andOKButton:(JSValue *)okButton andCancelButton:(JSValue *)cancelButton andNowdate:(NSString *)nowdate andMaxdate:(NSString *)maxdate andMindate:(NSString *)mindate andID:(NSString *)ID andFormat:(NSString *)format;

-(instancetype)initWithTitle:(NSString *)title andFormat:(NSString *)format andCancelButtonTitle:(JSValue *)cancelButtonTitle andOtherButtonTitles:(NSValue *)otherButtonTitles;

@end
