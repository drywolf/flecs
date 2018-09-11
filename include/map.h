#ifndef REFLECS_MAP_H
#define REFLECS_MAP_H

#include <reflecs/platform.h>
#include <reflecs/iter.h>
#include <reflecs/array.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsMap EcsMap;

typedef struct EcsMapIter {
    EcsIter bucket_iter;
    EcsArrayIter bucket_iter_data;
    uint32_t bucket_index;
} EcsMapIter;

EcsMap* ecs_map_new(
    uint32_t size);

void ecs_map_free(
    EcsMap *map);

uint32_t ecs_map_count(
    EcsMap *map);

uint32_t ecs_map_bucket_count(
    EcsMap *map);

void ecs_map_clear(
    EcsMap *map);

void ecs_map_set(
    EcsMap *map,
    uint64_t key_hash,
    const void *data);

EcsResult ecs_map_remove(
    EcsMap *map,
    uint64_t key_hash);

void* ecs_map_get(
    EcsMap *map,
    uint64_t key_hash);

EcsIter _ecs_map_iter(
    EcsMap *map,
    EcsMapIter *iter_data);

#define ecs_map_iter(me)\
    _ecs_map_iter(me, alloca(sizeof(EcsMapIter)))

#ifdef __cplusplus
}
#endif

#endif
