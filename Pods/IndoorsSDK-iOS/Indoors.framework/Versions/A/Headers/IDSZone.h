//
//  Zone.h
//  Indoors
//
//  Created by Gerhard Zeissl on 02.12.12.
//  Copyright (c) 2012 Indoors. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    IDSZoneTypePOI,
    IDSZoneTypeDeadZone,
    IDSZoneTypeInbound
} IDSZoneType;

@interface IDSZone : NSObject
@property (nonatomic) long zone_id;
@property (nonatomic, strong) NSString *name;
@property (nonatomic) NSUInteger floor_id;
@property (nonatomic, strong) NSString *zoneDescription;
@property (nonatomic) NSUInteger speed;
@property (nonatomic, strong) NSMutableArray *points;

- (UIBezierPath *)polygonPath;
@end
