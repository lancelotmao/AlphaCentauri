//
//  MRContextMenu.h
//  MRuntime
//
//  Created by kefoqing on 15/10/26.
//  Copyright © 2015年 huawei. All rights reserved.
//

#import "MRView.h"
#import <JavaScriptCore/JavaScriptCore.h>
@protocol MRContextMenuExport <JSExport>

- (void)setChoeseCallbackForJS:(JSValue *)jsFunction;

@end
@protocol selectMenuItemDelegate <NSObject>

- (void)selectMenuItemIndex :(NSInteger)index;

@end
@interface MRContextMenu : MRView<MRContextMenuExport>
@property (nonatomic,assign) id<selectMenuItemDelegate>selectMenuItemDelegate;
@property (nonatomic,strong) JSManagedValue *jsFunction;
- (void)showContextMenu :(NSDictionary*)contextAttrs andMenu:(NSArray *)menuItems;
@end
