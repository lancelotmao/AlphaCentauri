//
//  MRRadioButton1.h
//  mWidget
//
//  Created by StevenHu on 14/12/19.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRView.h"
@class RadioButton;
@interface MRRadioGroup : MRView<MRJSView>
@property (nonatomic,strong) RadioButton *radioButton;

@end
