//
//  MMLInflater.h
//  MMLInflater
//
//  Created by mCloud on 14/12/24.
//  Copyright (c) 2014年 Huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "MRViewController.h"
#import "MMLData.h"


@interface MMLInflater : NSObject

@property(nonatomic,strong)NSMutableDictionary *attrDic;
@property(nonatomic,strong)NSMutableArray *arr;

- (instancetype)initWithContext:(MRContext*) context;
- (MRPage*)inflate:(MMLData*) data;
- (MRView*)inflateView:(MMLViewData*) viewInfo;
+ (Class)getElementClass:(NSString *)key;
@end
