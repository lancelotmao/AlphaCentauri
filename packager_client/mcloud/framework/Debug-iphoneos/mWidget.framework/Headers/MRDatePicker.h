//
//  MRDatePickerDialog.h
//  UIDatePick
//
//  Created by rossyang on 14/12/15.
//  Copyright (c) 2014年 huawei. All rights reserved.
//

#import "MRView.h"
//#import "PropertiesManager.h"
typedef enum {
    MRDatePickerModeTime,
    MRDatePickerModeDate,
    MRDatePickerModeDateAndTime,
    MRDatePickerModeCountDownTimer,
}MRDatePickerMode;

@interface MRDatePicker : MRView<MRJSView>
@property(nonatomic,strong,readonly)UIDatePicker *MRDatePicker;
- (void)creatDatePickerWithMinDate: (NSString *)minDate andMaxDate:(NSString *)maxDate andnowDate: (NSString *)nowDate andformat:(NSString *)format;

@end
