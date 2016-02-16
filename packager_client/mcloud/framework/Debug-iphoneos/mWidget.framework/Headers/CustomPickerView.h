//
//  CustomPickerView.h
//  MRuntime
//
//  Created by hushengcai on 15/11/10.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PickerViewData.h"

typedef enum {
    MRNumberPickerView = 0,
    MRTimePickerView,
    MRDatePickerView,
    MRDateTimePickerView,
    MRStringPickerView,
}MRPickerViewType;

typedef void (^getDataBlock)(id);

@interface CustomPickerView : UIView

@property (nonatomic, assign)CGSize autoSize;

@property (nonatomic,assign)MRPickerViewType pickerViewType;
@property (nonatomic,strong)UIPickerView *pickerView;
@property (nonatomic,copy) NSString *format;


@property (nonatomic,assign)NSInteger oldSelectDay;

@property (nonatomic,assign)BOOL isZh_CN;

@property (nonatomic,copy)NSString *selectValue;

@property (nonatomic,copy)NSString *selectYear;
@property (nonatomic,copy)NSString *selectMonth;
@property (nonatomic,copy)NSString *selectDay;
@property (nonatomic,copy)NSString *selectHour;
@property (nonatomic,copy)NSString *selectMinut;
@property (nonatomic,copy)NSString *selectAMPM;

@property (nonatomic,copy)NSString *pickerWidth;
@property (nonatomic,copy)getDataBlock dataBlock;
@property (nonatomic,strong)PickerViewData *picViewData;


@end
