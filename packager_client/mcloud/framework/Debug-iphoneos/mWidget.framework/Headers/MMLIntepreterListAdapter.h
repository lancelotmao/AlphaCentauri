//
//  MMLIntepreterListAdapter.h
//  MMLInflater
//
//  Created by mCloud on 15/1/15.
//  Copyright (c) 2015年 Huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MRAdapter.h"
@class MMLInflater;

@interface MMLIntepreterListAdapter : MRBaseListAdapter

@property (nonatomic, strong) MMLInflater* inflater;

@property (nonatomic, strong) NSArray* sectionTemplates;
@property (nonatomic, strong) NSArray* itemTemplates;
@property (nonatomic, strong) NSArray* menuTemplates;

//kfq
@property (nonatomic, strong) NSArray* contextMenu;

@end
