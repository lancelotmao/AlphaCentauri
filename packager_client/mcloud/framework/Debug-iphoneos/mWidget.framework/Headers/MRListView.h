//
//  MRListView.h
//  mWidget
//
//  Created by lucaiguang on 14/12/26.
//  Copyright (c) 2014年 huawei. All rights reserved.
//

#import "MRView.h"
#import "Menu.h"


//@protocol MRListViewExport <JSExport>
//- (void)afterBind:(NSString *)jscode;
//- (void)itemTap:(NSString *)jscode;
//- (void)itemSwipeLeft:(NSString *)jscode;
//- (void)itemSwipeRight:(NSString *)jscode;
//- (void)scrollUp:(NSString *)jscode;
//- (void)scrollDown:(NSString *)jscode;
//@end

@class MRBaseListAdapter;

@protocol MRJSListView <JSExport,MRJSView>

- (int)getFirstVisiblePosition;
- (int)getLastVisiblePosition;

- (MRView*)findCellWithIndexAndId:(int)index :(NSString*)cellId;

- (NSArray*)mergeCell :(uint)setionIndex :(uint)firstIndex :(uint)length;

- (MRView*)findCellByIndex:(int)index;


JSExportAs(getHeaderViewItem, - (MRView*)headerViewItem:(NSString*)viewId);
//JSExportAs(getFooterViewItem, - (MRView*)footerViewItem:(NSString*)viewId);

@end

@class MRDIYHeader;
@class MRDIYFooter;
@interface MRListView : MRView <MRJSListView>

@property (nonatomic, strong) NSArray *effectArray;
@property (nonatomic, assign) BOOL isSelect;
@property (nonatomic, strong) MRBaseListAdapter *adapter;
@property (nonatomic, strong) MRDIYHeader *diyHeaderRefresh;
@property (nonatomic, strong) MRDIYFooter *diyFooterRefresh;

- (void)addMenu:(Menu*)menu;
- (NSArray*)findCellsById:(NSString*)viewId;
- (NSArray*)findCellsByPoint:(CGPoint)point;
- (MRView*)headerViewItem:(NSString*)viewId;
//- (MRView*)footerViewItem:(NSString*)viewId;

@end
