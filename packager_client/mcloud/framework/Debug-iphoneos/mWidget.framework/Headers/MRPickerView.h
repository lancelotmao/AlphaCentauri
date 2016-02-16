//
//  MRPickerView.h
//  MRuntime
//
//  Created by hushengcai on 15/11/10.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import "MRView.h"
@class MRPickerView;
@protocol MRJSPickerView <JSExport,MRJSView>

- (NSString *)getValue;
@end
@interface MRPickerView : MRView<MRJSPickerView>
@property (nonatomic,strong)UIView *pickerView;

@end
