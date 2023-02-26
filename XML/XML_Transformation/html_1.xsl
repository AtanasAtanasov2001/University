<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Игра</h1>
                <table border="5" align="center">
                    <tr>
                        <th>Име</th>
                        <th>Цена</th>
                        <th>Създател</th>
                        <th>Местоположение на разработчика</th>
                        <th>Бюджет</th>   
                    </tr>         
                    <xsl:for-each select="game_library/game">
                        <tr>
                            <td>
                                <xsl:call-template name="game-name"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-price"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-manufacturer-name"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-manufacturer-location"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-manufacturer-salary"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="game-name">
        <xsl:value-of select="game_name/."/>
    </xsl:template>

    <xsl:template name="game-price">
        <xsl:value-of select="price/."/>
    </xsl:template>

    <xsl:template name="game-manufacturer-name">
        <xsl:value-of select="manufacturer/name/."/>
    </xsl:template>

    <xsl:template name="game-manufacturer-location">
        <xsl:value-of select="manufacturer/location/."/>
    </xsl:template>

    <xsl:template name="game-manufacturer-salary">
        <xsl:value-of select="manufacturer/salary/."/>
    </xsl:template>

</xsl:stylesheet>