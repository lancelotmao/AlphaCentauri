//
//  MRAdapter.h
//  mWidget
//
//  Created by lucaiguang on 15/1/9.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MRLayout.h"

//add by hongjinliang for compiler
typedef NS_ENUM(NSInteger, MRTemplateType) {
    MRTemplateTypeCell = 1,
    MRTemplateTypeSection = 2,
    MRTemplateTypeCollectionCell = 3
};
//end

@interface MRRange : NSObject
@property (nonatomic, readwrite) int offset;
@property (nonatomic, readwrite) int size;
@end

@interface MRContextMenuItem : NSObject
@property (nonatomic, copy) NSString* title;
@property (nonatomic, copy) NSString* icon;
@property (nonatomic, copy) NSString* background;
@property (nonatomic, copy) NSString* visibility;
@property (nonatomic, copy) NSString* disabled;
@property (nonatomic, copy) NSString* border;
@property (nonatomic, copy) NSString* borderSize;
@property (nonatomic, copy) NSString* borderColor;
@property (nonatomic, copy) NSString* borderType;
@property (nonatomic, copy) NSString* radius;
@property (nonatomic, copy) NSString* onClickHandler;

@end


@interface MRBaseListAdapter : NSObject <UITableViewDataSource>

@property (nonatomic, strong) NSMutableDictionary* cellMap;
@property (nonatomic, weak) id<MRDataSourceDelegate> source;
@property (nonatomic, weak) id<MRScriptExecutor> scriptExecutor;
@property (nonatomic, assign) NSString* itemTemplateSelectedFilter;
@property (nonatomic, assign) NSString* menuTemplateSelectedFilter;

@property (nonatomic, assign) NSString *groupBy;
@property (nonatomic, assign) NSString *indexer;
@property (nonatomic, copy)   NSString *sectionHeaderVisible;
@property (nonatomic, copy)   NSString *showIndexer;
@property (nonatomic, copy) NSString *effect;
@property (nonatomic, assign) BOOL expandable;
@property (nonatomic, assign) BOOL isHorizontal;
@property (nonatomic, assign) BOOL footerDividersEnabled;
@property (nonatomic, strong)  MRView *headerView;
@property (nonatomic, assign) BOOL disabled;
@property (nonatomic, assign) BOOL showDivider;



@property (nonatomic, strong) NSMutableArray *cellViews;
@property (nonatomic, strong) NSMutableDictionary *collectCellHeights;
@property (nonatomic, assign) CGFloat collectionViewCellHeight;
@property (nonatomic, assign) CGFloat collectionViewCellWidth;


@property (nonatomic, weak) UITableView* tableView;
@property (nonatomic, weak) UICollectionView* collectionView;
@property (nonatomic, weak)MRContext *context;

@property (nonatomic, strong) NSMutableDictionary *dicHeadersCreated;

-(MRView*) createViewWithTemplateIndex:(NSInteger)index;
-(MRView*) createViewWithSectionTemplateIndex:(NSInteger)index;
-(MRContextMenuItem*) getMenuItemWithTemplateIndex:(NSInteger)index;

-(NSArray*) getItemTemplateFilters;
-(NSArray*) getMenuTemplateFilters;

- (NSDictionary*)getContextMenuAttrs;

//-(NSInteger) getItemTempleteIndex:(NSInteger)cellIndex;



- (void) reloadDataWithIdentify:(NSString *)identify;
- (CGFloat)heightForHeaderInSection:(UITableView *)tableView :(NSInteger)section;
- (UIView *)viewForHeaderInSection:(UITableView *)tableView :(NSInteger)section;
- (CGFloat)heightForRowAtIndexPath:(UITableView *)tableView :(NSIndexPath *)indexPath;
- (CGFloat)estimatedHeightForRowAtIndexPath:(UITableView *)tableView :(NSIndexPath *)indexPath;
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath isHorizontal:(BOOL)isHorizontal;
- (NSInteger)getSelectedIndex:(NSIndexPath *)indexPath;

//add menu
- (NSArray *)tableView:(UITableView *)tableView editActionsForRowAtIndexPath:(NSIndexPath *)indexPath;
// for GridView
- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath;
- (NSArray*)findCellsById:(NSString*)viewId;
- (MRView*)findCellWithIndexAndId:(int)index :(NSString*)cellId;

//get session array
- (NSMutableDictionary*)sessions;
// get cell array
- (NSMutableDictionary*)cells;

- (NSInteger)sessionCount;
- (NSInteger)cellCount;

- (NSArray*)getCellViewArray;
- (NSArray*)mergeCellByAdapter :(uint)setionIndex :(uint)firstIndex :(uint)length :(BOOL)hideDivider;
- (MRView*)findCellByIndex:(int)index;

@end
