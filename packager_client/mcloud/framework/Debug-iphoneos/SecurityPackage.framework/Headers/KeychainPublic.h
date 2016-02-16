//
//  KeychainPublic.h
//  FileContainer
//
//  Created by mcloud－sec on 15/4/14.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#ifndef FileContainer_KeychainPublic_h
#define FileContainer_KeychainPublic_h

@interface  KeychainPublic : NSObject
/**************************************************************/
// keychain设置函数
// 参数:
//			key-[IN]key
//			value-[IN]对应的键值
// 返回值: 成功：YES 失败：NO
/**************************************************************/
+ (bool)setKeyChain:(NSString*)key ofvalue:(id)value;//设置keychain
/**************************************************************/
// 根据key获取对应键值函数
// 参数:
//			key-[IN]key
// 返回值: 成功：键值 失败：NIL
/**************************************************************/

+ (id)getKeyValue:(NSString*)key;//获取value
/**************************************************************/
// 清空对应的Key
// 参数:
//			key-[IN]key
/**************************************************************/

+ (void)resetKeyChain:(NSString*)key;//删除key
@end

#endif
