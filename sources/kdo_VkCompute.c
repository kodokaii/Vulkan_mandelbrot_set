/* *********************************************************************************** */
/*       :::    ::: ::::::::  :::::::::   ::::::::  :::    :::     :::     ::::::::::: */
/*      :+:   :+: :+:    :+: :+:    :+: :+:    :+: :+:   :+:    :+: :+:       :+:      */
/*     +:+  +:+  +:+    +:+ +:+    +:+ +:+    +:+ +:+  +:+    +:+   +:+      +:+       */
/*    +#++:++   +#+    +:+ +#+    +:+ +#+    +:+ +#++:++    +#++:++#++:     +#+        */ /*   +#+  +#+  +#+    +#+ +#+    +#+ +#+    +#+ +#+  +#+   +#+     +#+     +#+         */ /*  #+#   #+# #+#    #+# #+#    #+# #+#    #+# #+#   #+#  #+#     #+#     #+#          */
/* ###    ### ########  #########   ########  ###    ### ###     ### ###########       */
/*                        <kodokai.featheur@gmail.com>                                 */
/* *********************************************************************************** */
#include "kdo_VkCompute.h"

void	kdo_zoom(GLFWwindow* window, double xoffset, double yoffset)
{
	Kdo_Vulkan	*vk;
	double		yMousse;
	double		xMousse;
	double		scrollSensitivity;
	double		mousseSensitivity;

	(void)	xoffset;
	vk	= ((Kdo_Vulkan *) glfwGetWindowUserPointer(window));

	glfwGetCursorPos(window, &xMousse, &yMousse);

	scrollSensitivity	=	vk->camera.radius * 0.1;
	mousseSensitivity	=	vk->camera.radius * 0.5;

	vk->camera.radius	-= scrollSensitivity * yoffset;
	vk->camera.pos[0]	+= (xMousse / (double)vk->swapChain.imagesExtent.width - 0.5) * mousseSensitivity;
	vk->camera.pos[1]	-= (yMousse / (double)vk->swapChain.imagesExtent.height - 0.5) * mousseSensitivity;
}

void kdo_compute(Kdo_Vulkan *vk)
{
	vk->compute.currentTime	= glfwGetTime();

	if (vk->compute.startTime == 0)
	{
		vk->compute.startTime = vk->compute.currentTime;
	}

	vk->compute.fps++;
	if (1 < vk->compute.currentTime - vk->compute.secondTime)
	{
		printf("%d\n", vk->compute.fps);
		vk->compute.fps = 0;
		vk->compute.secondTime = vk->compute.currentTime;
	}
}
