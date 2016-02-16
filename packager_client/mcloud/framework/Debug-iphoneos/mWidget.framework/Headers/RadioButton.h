//
//  MRCheckBox1.h
//  mWidget
//
//  Created by StevenHu on 14/12/5.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRView.h"
#import "RadioItem.h"
typedef enum : NSUInteger {
     vertical,//竖立 default is 竖立
     horizontal,//水平
    
} RadioButtonStlye;

@protocol RadioButtonValueChangeDelegate <NSObject>
- (void)postButtonIndex:(NSString *)value :(NSUInteger)selectIndex;
@end
@interface RadioButton : UIView
@property (nonatomic ,strong)NSString *checkedItem;
@property (nonatomic,assign) RadioButtonStlye radioButtonstyle;
@property (nonatomic, assign) id<RadioButtonValueChangeDelegate>delegate;
@property (nonatomic, assign)CGSize autoSize;
@property (nonatomic,strong) RadioItem * selectedItem;
@property (nonatomic,assign)int selectTag;
- (CGSize)measureRadioButtonSize;


@end

