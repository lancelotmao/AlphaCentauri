//
//  MRNumberPickerDialog.h
//  MRNumberPickerDialog
//
//  Created by rossyang on 14/12/17.
//  Copyright (c) 2014年 huawei. All rights reserved.
//

#import <MRuntime/MRuntime.h>
#import "MRView.h"

@interface MRNumberPicker : MRView<MRJSView>

@property(nonatomic,strong,readonly)UIPickerView *MRPickerView;

@end
