//
//  MRGrid.h
//  mWidget
//
//  Created by Nil on 22/12/14.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import "MRListView.h"
#import "MRView.h"
@protocol MRGridViewExport <JSExport,MRJSView>

- (UICollectionView *)getCollectionView ;
- (NSArray *)getCollectionViewCellSubViews:(NSIndexPath *)indexPath;
- (UICollectionViewCell *)getCollectionViewCell:(NSIndexPath *)indexPath;
@end
@interface MRGrid : MRListView<MRGridViewExport>
@property (nonatomic, strong) UICollectionView *collectionView;
@property(nonatomic, weak)JSValue *jsFunction;

@end
