//
//  MRBaseDataSource.h
//  MRuntime
//
//  Created by lucaiguang on 15/1/20.
//  Copyright (c) 2015年 HuaWei. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MRDataChangeDelegate <NSObject>
@optional
- (void)onDataSourceChanged;
@end

@protocol MRDataSourceDelegate <NSObject>
- (void)addDataSourceOberver:(id<MRDataChangeDelegate>)delegate;
- (void)removeDataSourceOberver:(id<MRDataChangeDelegate>)delegate;
- (void)notifyDataSourceChanged;

- (NSInteger)getCount;
- (NSDictionary *)getRow:(NSInteger)row;
- (BOOL)updateValue:(NSInteger)index forPath:(NSArray*)path withValue:(NSString*)value;

- (void)removeArray:(NSInteger)row;

- (void)exchangeObjectAtIndex:(NSInteger)index andTop:(NSInteger)topIndex;

- (void)stop;
@end

@interface MRBaseDataSource : NSObject <MRDataSourceDelegate>

@end
