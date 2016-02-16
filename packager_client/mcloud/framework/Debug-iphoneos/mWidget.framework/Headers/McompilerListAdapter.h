//
//  MMLIntepreterListAdapter.h
//  MMLInflater
//
//  Created by mCloud on 15/1/15.
//  Copyright (c) 2015年 Huawei. All rights reserved.
//  create this class for compile module


#import "MRAdapter.h"

typedef MRView * (^createView)();

@interface MRItemTemplate : NSObject

@property (nonatomic, copy ) createView handler;
@property (nonatomic, strong ) NSString *selectFilter;


- (instancetype) initWithHandler:(createView)handler andFilter:(NSString *)filter;

@end


@interface McompilerContextMenuItem : MRContextMenuItem

@property (nonatomic ,strong) NSString *selectFilter;

@end



@interface McompilerListAdapter : MRBaseListAdapter
@property (nonatomic, strong) NSArray *templates; //cell 模板组
@property (nonatomic, strong) NSArray *sectionTemplates;
@property (nonatomic, strong) NSArray *menuTemplates;
@property (nonatomic, strong) NSArray *collectionCellTemplates;
@end