//
//  MRSmartLayoutParams.h
//  mWidget
//
//  Created by Nil on 16/9/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <mWidget/mWidget.h>
#import "MRSmartLayoutRelationship.h"
@interface MRSmartLayoutParams : MRLayoutParams

@property(nonatomic,assign) MRSmartLayoutRelationship* smartLeft;
@property(nonatomic,assign) MRSmartLayoutRelationship* smartRight;
@property(nonatomic,assign) MRSmartLayoutRelationship* smartTop;
@property(nonatomic,assign) MRSmartLayoutRelationship* smartBottom;
@property(nonatomic,assign) MRSmartLayoutRelationship* smartCenterX;
@property(nonatomic,assign) MRSmartLayoutRelationship* smartCenterY;
@property(nonatomic,assign) MRSmartLayoutRelationship* smartWidth;
@property(nonatomic,assign) MRSmartLayoutRelationship* smartHeight;

@property(nonatomic, strong) NSMutableArray* constraints;
@property(nonatomic, strong) NSMutableArray* superConstraints;

@end