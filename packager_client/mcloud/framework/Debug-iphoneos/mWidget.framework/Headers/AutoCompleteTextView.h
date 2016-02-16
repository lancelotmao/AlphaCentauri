//
//  AutoCompleteTextView.h
//  mWidget
//
//  Created by Nil on 17/3/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRView.h"
#import "TextInput.h"

@protocol AutoCompleteTextViewDelegate <NSObject>
- (void)onTextChange:(NSString *)text;
@end

@interface AutoCompleteTextView : UIView
@property (nonatomic, strong) TextInput *textInput;
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, assign) int dropDownRows;
@property (nonatomic, assign) int minNumber;
@property (nonatomic, assign) CGFloat minTime;
@property (nonatomic, assign) CGFloat dropDowmHeight;
@property (nonatomic, copy)   NSString *hintText;
@property (nonatomic, copy)   NSString *gravityHorizontal;
@property (nonatomic, strong) NSArray  *dataSource;
@property (nonatomic, strong)NSString *text;
@property (nonatomic, assign)CGFloat textSize;
@property (nonatomic, assign) BOOL textBold;
@property (nonatomic, strong)UIColor *textColor_normal;
@property (nonatomic, strong)UIColor *background_color;
@property (nonatomic, strong)UIImage *backImage;
@property (nonatomic, assign) id<AutoCompleteTextViewDelegate> delegate;



- (void)setTableViewHidden:(BOOL)hidden;

@end
