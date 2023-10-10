/* *********************************************************************************** */
/*       :::    ::: ::::::::  :::::::::   ::::::::  :::    :::     :::     ::::::::::: */
/*      :+:   :+: :+:    :+: :+:    :+: :+:    :+: :+:   :+:    :+: :+:       :+:      */
/*     +:+  +:+  +:+    +:+ +:+    +:+ +:+    +:+ +:+  +:+    +:+   +:+      +:+       */
/*    +#++:++   +#+    +:+ +#+    +:+ +#+    +:+ +#++:++    +#++:++#++:     +#+        */
/*   +#+  +#+  +#+    +#+ +#+    +#+ +#+    +#+ +#+  +#+   +#+     +#+     +#+         */
/*  #+#   #+# #+#    #+# #+#    #+# #+#    #+# #+#   #+#  #+#     #+#     #+#          */
/* ###    ### ########  #########   ########  ###    ### ###     ### ###########       */
/*                        <kodokai.featheur@gmail.com>                                 */
/* *********************************************************************************** */

#ifndef KDO_VKLOAD_H
# define KDO_VKLOAD_H

# include "kdo_Vulkan.h"
# include "kdo_VkMemory.h"

typedef struct Kdo_VkObjectInfoElement
{
	uint32_t		maxCount;
	uint32_t		*matchArray;
}	Kdo_VkObjectInfoElement;

typedef struct Kdo_VkObjectInfo
{
	Kdo_VkObjectInfoElement	pos;
	Kdo_VkObjectInfoElement	tangent;
	Kdo_VkObjectInfoElement	bitangent;
	Kdo_VkObjectInfoElement	normal;
	Kdo_VkObjectInfoElement	uv;
	Kdo_VkObjectInfoElement	material;
	Kdo_VkObjectInfoElement	texture;
	uint32_t				vertexMaxCount;
	uint32_t				vertexCount;
	Kdo_VkVertex			*vertex;
	Kdo_VkObject			object;
}   Kdo_VkObjectInfo;

VkResult	kdo_initObject(Kdo_Vulkan *vk, Kdo_VkObjectInfo *objectInfo,
							uint32_t maxVertexCount,
							uint32_t maxPosCount,
							uint32_t maxTangentCount,
							uint32_t maxBitangentCount,
							uint32_t maxNormalCount,
							uint32_t maxUvCount,
							uint32_t maxMaterialCount,
							uint32_t maxTextureCount);
VkResult	kdo_addPosObject(Kdo_Vulkan *vk, Kdo_VkObjectInfo *objectInfo, uint32_t index, vec4 pos);
VkResult	kdo_addTangentObject(Kdo_Vulkan *vk, Kdo_VkObjectInfo *objectInfo, uint32_t index, vec4 tangent);
VkResult	kdo_addBitangentObject(Kdo_Vulkan *vk, Kdo_VkObjectInfo *objectInfo, uint32_t index, vec4 bitangent);
VkResult	kdo_addNormalObject(Kdo_Vulkan *vk, Kdo_VkObjectInfo *objectInfo, uint32_t index, vec4 normal);
VkResult	kdo_addUvObject(Kdo_Vulkan *vk, Kdo_VkObjectInfo *objectInfo, uint32_t index, vec2 uv);
VkResult	kdo_addTextureObject(Kdo_Vulkan *vk, Kdo_VkObjectInfo *objectInfo, uint32_t index, char *path);
VkResult	kdo_addMaterialObject(Kdo_Vulkan *vk, Kdo_VkObjectInfo *objectInfo, uint32_t index, Kdo_VkMaterial *material);
VkResult	kdo_addTriangleObject(Kdo_Vulkan *vk, Kdo_VkObjectInfo *objectInfo, Kdo_VkVertex vertexIn[3]);

VkResult    kdo_openObject(Kdo_Vulkan *vk, char *objectPath, Kdo_VkObjectInfo *objectInfo);
VkResult	kdo_loadObject(Kdo_Vulkan *vk, uint32_t objectCount, Kdo_VkObjectInfo *info);

#endif
