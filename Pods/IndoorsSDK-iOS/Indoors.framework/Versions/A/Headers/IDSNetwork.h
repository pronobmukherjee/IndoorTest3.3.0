//
//  Network.h
//  FMDBTest
//
//  Created by Gerhard Zeissl on 04.03.13.
//
//

#import <Foundation/Foundation.h>
#import "IDSBuilding.h"
#import "Networktype.h"


@interface IDSNetwork : NSObject
@property (nonatomic) NSInteger networkID;
@property (nonatomic) uint64_t bssid;
@property (nonatomic) NSInteger channel;
@property (nonatomic, strong) NSString *name;
@property (nonatomic) NSInteger refreshrate;
//@property (nonatomic, strong) IDSBuilding* building;
@property (nonatomic) NSInteger buildingID;
@property (nonatomic) Networktype networktype;
// keys: x, y, floor_id, ibeaon_uuid (only iBeacon), ibeacon_major (only iBeacon), ibeacon_minor (only iBeacon)
@property (nonatomic) NSDictionary *metaData;

- (NSInteger)hashCode;


@end
