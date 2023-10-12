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
	vk->camera.center[0]	+= (xMousse / (double)vk->swapChain.imagesExtent.width - 0.5) * mousseSensitivity;
	vk->camera.center[1]	-= (yMousse / (double)vk->swapChain.imagesExtent.height - 0.5) * mousseSensitivity;
}

void	updateCamera(Kdo_Vulkan *vk)
{
	double	sensitivity;

	sensitivity	= vk->camera.radius * 0.01;

	if ((glfwGetKey(vk->window.path, GLFW_KEY_D)) == GLFW_PRESS)
		vk->camera.Z0[0]	+= sensitivity;

	if ((glfwGetKey(vk->window.path, GLFW_KEY_A)) == GLFW_PRESS)
		vk->camera.Z0[0]	-= sensitivity;

	if ((glfwGetKey(vk->window.path, GLFW_KEY_W)) == GLFW_PRESS)
		vk->camera.Z0[1]	+= sensitivity;

	if ((glfwGetKey(vk->window.path, GLFW_KEY_S)) == GLFW_PRESS)
		vk->camera.Z0[1]	-= sensitivity;

	if ((glfwGetKey(vk->window.path, GLFW_KEY_Q)) == GLFW_PRESS)
		vk->camera.iterMax	+=	vk->camera.iterMax / 10;

	if ((glfwGetKey(vk->window.path, GLFW_KEY_E)) == GLFW_PRESS && 10 < vk->camera.iterMax)
		vk->camera.iterMax	-=	vk->camera.iterMax / 10;

	if ((glfwGetKey(vk->window.path, GLFW_KEY_SPACE)) == GLFW_PRESS)
	{
		vk->camera.Z0[0]	= 0;
		vk->camera.Z0[1]	= 0;
	}

	if ((glfwGetKey(vk->window.path, GLFW_KEY_LEFT_SHIFT)) == GLFW_PRESS)
		printf("iterMax = %u\n", vk->camera.iterMax);
}

void kdo_compute(Kdo_Vulkan *vk)
{
	vk->compute.currentTime	= glfwGetTime();

	updateCamera(vk);

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
